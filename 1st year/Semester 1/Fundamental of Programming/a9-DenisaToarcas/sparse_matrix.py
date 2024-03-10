from scipy.sparse import csr_matrix
from scipy.sparse import csc_matrix

matrix = [[1, 0, 0],
          [0, 2, 0],
          [0, 0, 3]]

sparse_matrix = csr_matrix(matrix)
print(sparse_matrix)

print()

sparse_matrix_1 = csc_matrix(matrix)
print(sparse_matrix_1)

print()

image = [[0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0],
         [0, 0, 1, 0, 0],
         [0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0]]

sparse_image = csr_matrix(image)
print(sparse_image)