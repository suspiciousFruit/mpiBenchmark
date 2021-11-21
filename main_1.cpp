#include <iostream>
#include <chrono>
#include <mpi.h>
#include <time.h>


#include <sys/resource.h>
#include <sys/times.h>


const int TAG = 1;
int main(int argc, char* argv[]) {
    MPI_Status status;
    int world_rank, world_size;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);


    if (world_rank == 0) {
        const time_t start_time = time(NULL);
        // MPI_Send(data, 4, MPI_INT, 1, TAG, MPI_COMM_WORLD);
        time_t end_time;
        MPI_Recv((void*)&end_time, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        const double dur = difftime(end_time, start_time);
        std::cout.precision(25);
        // std::cout << "dur " << dur << std::endl;
        std::cout << end_time << ' ' << start_time << std::endl;
    }
    else {
        // MPI_Recv((void*)arr, 4, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        for (int i = 0; i < 1000000; ++i) {
            const a = i * 189 - i % 23 + i * i;
        }
        const time_t end_time = time(NULL);
        MPI_Send((void*)&end_time, 1, MPI_DOUBLE, 0, TAG, MPI_COMM_WORLD);

        //std::cout << time(NULL) << std::endl; // 8
    }

    MPI_Finalize();
}