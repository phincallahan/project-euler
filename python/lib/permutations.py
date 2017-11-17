def binary_permutations(end):
    def __inner(perm, end):
        yield ''.join(perm)
        for i in range(end):
            perm[i] = '1' 
            yield from __inner(perm, i)
            perm[i] = '0'

    perm = []
    for i in range(end):
        perm.append('1')
        yield from __inner(perm, i)
        perm[i] = '0'
