// Arquitectura de Computadores II - Taller 3

#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <arm_neon.h>

void fill_array(    const int n,
                    float *array )
{
    for( int i=0; i < n; i++ )
    {
        array[i] = rand()/(RAND_MAX/n);
    }
}

void serial_saxpy(  const int n,
                    const float num,
                    float *x,
                    float *y )
{
    for( int i=0; i < n; i++ )
    {
        y[i] = num * x[i] + y[i];
    }   
}

void parallel_saxpy(    const int n,
                        const float num,
                        float *x,
                        float *y )
{
    float32x4_t v_scale = vdupq_n_f32(num);
    float32x4_t v_x, v_y, v_r;
    
    #pragma omp parallel for
    for (int i = 0; i < n; i += 4)  {
        v_x = vld1q_f32(x + i);
        v_y = vld1q_f32(y + i);
        v_x = vmulq_f32(v_x, v_scale);
        v_r = vaddq_f32(v_x, v_y);
        vst1q_f32(y + i, v_r);
    }   
}

int main( int argc, char *argv[] )
{
    printf( "START\n" );
    srand( time(NULL) );

    int size = atoi( argv[1] );
    const int num = atoi( argv[2] );
    float *x = malloc( sizeof(float)*size );
    float *y = malloc( sizeof(float)*size );

    fill_array( size, x );
    fill_array( size, y );

    double start_time_serial, run_time_serial;
    double start_time_parallel, run_time_parallel;

    start_time_serial = omp_get_wtime();
    serial_saxpy( size, num, x, y );
    run_time_serial = omp_get_wtime() - start_time_serial;

    start_time_parallel = omp_get_wtime();
    parallel_saxpy( size, num, x, y );
    run_time_parallel = omp_get_wtime() - start_time_parallel;

    printf( "Serial time: %f\n", run_time_serial );
    printf( "Parallel time: %f\n", run_time_parallel );

    printf( "END.\n" );

    return 0;
}
