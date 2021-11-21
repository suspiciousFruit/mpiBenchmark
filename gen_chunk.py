import random


def genfile(size, filename):
    with open(filename, 'w') as file:
        for i in range(size):
            file.write(str(random.random()))



# sizes = [Mb // 2, Mb, Mb*2, Mb*3, Mb*4, Mb*5, Mb*6, Mb*7, Mb*8, Mb*9, Mb*10]

# for size in sizes:
#     genfile(size, f'chunks/chunck_{size}.txt')
#     print(f'file with size {size} created')

Mb = 2**20
genfile(10 * Mb, "chunck.txt")