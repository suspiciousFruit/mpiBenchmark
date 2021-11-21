
with open("all_results.txt", 'w') as resfile:
    for size in [1, 2, 5, 8, 10]:
        sum = 0.0
        count = 0
        with open(f'results/res_{size}Mb.txt') as file:
            for line in file:
                sum += float(line)
                count += 1
        resfile.write(f'[{size} Mb] time: {sum / count} sec\n')