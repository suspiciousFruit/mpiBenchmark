#include <iostream>
#include <mpi.h>
#include <fstream>
#include <iomanip>
#include <string>

const int TAG = 1;
const size_t Mb = 1024 * 1024;


char* readFile(std::string filename, size_t filesize) {
    char* data = new char[filesize];
    std::ifstream file;
    file.open(filename, std::ios::in | std::ios::binary);
    file.read(data, filesize);
    return data;
}

int main(int argc, char* argv[]) {
    int world_rank, world_size;
    // const size_t loop_number = 16;
    const size_t filesize = ((argc > 1) ? atoi(argv[1]) : 1) * Mb;
    // const size_t filesize = 10 * Mb;
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    const char* data = (world_rank == 0) ? readFile("chunk.txt", filesize) : new char[filesize];

    // double sumtime = 0.0;
    // for (int i = 0; i < loop_number; ++i) {

        if (world_rank == 0) {
            const double start_time = MPI_Wtime();

            MPI_Send((void*)data, filesize, MPI_CHAR, 1, TAG, MPI_COMM_WORLD);
            MPI_Barrier(MPI_COMM_WORLD);

            const double end_time = MPI_Wtime();
            // sumtime += end_time - start_time;
            // std::cout << "[" << i << "] " <<
            // std::setprecision(10) << (end_time - start_time) << std::endl;
            std::cout << std::setprecision(10) << (end_time - start_time) << std::endl;
            
        }
        else {
            MPI_Status status;
            MPI_Recv((void*)data, filesize, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);      
            MPI_Barrier(MPI_COMM_WORLD);
        }

    // }
    
    delete[] data;

    // if (world_rank == 0) {
    //     std::cout << "average time: "
    //         << std::setprecision(10) << sumtime / loop_number << std::endl;
    // }

    MPI_Finalize();
}