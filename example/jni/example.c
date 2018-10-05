// Arquitectura de Computadores II - Taller 3

#include <stdio.h>
#include <omp.h>
#include <math.h>

long factorial( const int pnum )
{
    long r = 1;
    for( int i=0; i <= pnum; i++ )
    {
        r *= i;
    }
    return r;
}

int calc_e(     const int pnum,
                const double pval )
{
    double r = 0;

    #pragma omp parallel for
    for( int i=0; i < pnum; i++ )
    {
        r += (pow( pval, i ) / factorial(i) );
    }
    return r;
}

int main( int argc, char *argv[] )
{
    printf( "START\n" );

    double t_start, t_run;
    int number = atoi( argv[1] );
    double val = atof( argv[2] );

    t_start = omp_get_wtime();
    calc_e( number, val );
    t_run = omp_get_wtime() - t_start;

    printf( "Time: %f s\n", t_run );

    printf( "END.\n" );
}
