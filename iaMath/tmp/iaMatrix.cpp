/* **************************************************************************************************** *
 *	Company	: iA
 *	File	: iaMatrix.cpp
 *	Author	: Aleksandr IUSHKEVICH
 *	Project	: Simple NeuroNet
 *	Version	: 2.0
 *
 *	Сreated	: October 2024
 *
 *	Description: class to realise matrix msthematique
 *
 * **************************************************************************************************** */
#include "iaMatrix.h"

/**
 * @brief Default constructor that initializes a 0x0 matrix.
 */
iaMatrix::iaMatrix() : iaMatrix(0) { } // Call constructor by one size with size 0

/**
 * @brief Constructor for a square matrix of size n x n.
 * @param n Size of the square matrix.
 */
iaMatrix::iaMatrix(int n) : iaMatrix(n, n) { } // Call constructor by two sizes with size n (square matrix)

/**
 * @brief Constructor for a rectangular matrix of size n x m.
 * @param n Number of rows in the matrix.
 * @param m Number of columns in the matrix.
 */
iaMatrix::iaMatrix(int n, int m) {
    this->n = (n == 0 && m > 0) ? 1 : n; // Set number of rows
    this->m = (n > 0 && m == 0) ? 1 : m; // Set number of columns
    this->vectors = *((this->n != 0) ? new iaVector[this->n]{} : nullptr); // Create array of vectors
    for (int i = 0; i < this->n; i++) { // Initialize each vector
        
//        this->vectors[i] = iaVector(this->m); // Create vector [i] with size m
    }
}

/**
 * @brief Constructor that initializes the matrix with given values.
 * @param n Number of rows in the matrix.
 * @param m Number of columns in the matrix.
 * @param values Pointer to an array of values to initialize the matrix.
 */
iaMatrix::iaMatrix(int n, int m, const double values[]) : iaMatrix(n, m) {
    for (int i = 0; i < n; i++) { // Iterate over rows
        for (int j = 0; j < m; j++) { // Iterate over columns
            this->vectors[i][j] = values[i * m + j]; // Save value in vector [i]
        }
    }
}

/**
 * @brief Copy constructor for the iaMatrix class.
 * @param otherMatrix The matrix to copy from.
 */
iaMatrix::iaMatrix(const iaMatrix& otherMatrix) : iaMatrix(otherMatrix.n, otherMatrix.m) {
    for (int i = 0; i < this->n; i++) { // Copy each vector
        this->vectors[i] = iaVector(otherMatrix.vectors[i]); // Create vector [i] as copy of vector [i] from other matrix
    }
}

/**
 * @brief Destructor for the iaMatrix class.
 */
iaMatrix::~iaMatrix() {
//    delete[] vectors; // Free allocated memory for vectors
}

/**
 * @brief Returns the number of vectors (rows) in the matrix.
 * @return Number of vectors.
 */
int iaMatrix::numberOfVectors() const {
    return n;
} //---numberOfVectors---

/**
 * @brief Returns the size of vectors (columns) in the matrix.
 * @return Size of vectors.
 */
int iaMatrix::sizeOfVectors() const {
    return m;
} //---sizeOfVectors---

/**
 * @brief Prints the matrix to the console.
 */
void iaMatrix::printMatrix() const {
    std::cout << "Matrix: \nNumber of Vectors - " << n << std::endl;
    std::cout << "Size of Vectors - " << m << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << "[" << i << "][" << j << "] " << vectors[i][j] << " | "; // Print each element
        }
        std::cout << std::endl; // New line after each row
    }
} //---printMatrix---

/*
#include "iaMatrix.h"

iaMatrix::iaMatrix() : iaMatrix(0) { }	// Call constructor by one size with size 0

iaMatrix::iaMatrix(int n) : iaMatrix(n, n) { }	// Call constructor by two sizes with size n (square matrix)

iaMatrix::iaMatrix(int n, int m) {
	this->n = ((n == 0 && m > 0) ? 1 : n);								// Set number of nets
	this->m = ((n > 0 && m == 0) ? 1 : m);								// Set number of inputs in net
	this->vectors = (this->n != 0 ? new iaVector[this->n]() : nullptr);	// Create vector of vectors with size 0
	for (int i = 0; i < this->n; i++) {									// Vectors:
		this->vectors[i] = iaVector(this->m);							// Recreate Vector [i] with size m
	}
}

iaMatrix::iaMatrix(int n, int m, const double values[]) : iaMatrix(n, m) {	// Call constructor by two sizes before with sizes n and m
	for (int i = 0; i < n; i++) {			// Vectors:
		for (int j = 0; j < m; j++) {		// Values if vector [i]:
			this->vectors[i][j] = *values;	// Save value [j] in vector [i]
			values++;						// Incrise pointer for input values
		}
	}
}

iaMatrix::iaMatrix(const iaMatrix& otherMatrix) : iaMatrix(otherMatrix.n, otherMatrix.m) {	//  Call constructor by two sizes with sizes of other matrix
	for (int i = 0; i < this->n; i++) {						// Vectors:
		this->vectors[i] = iaVector(otherMatrix.vectors[i]);	// Create vector [i] as copy of vector [i] from other matrix
	}
}

iaMatrix::~iaMatrix() { }

int iaMatrix::numberOfVectors() const {
	return n;
} //---numberOfVectors---

int iaMatrix::sizeOfVectors() const {
	return m;
} //---sizeOfVectors---

void iaMatrix::printMatrix() const {
	std::cout << "Matrix : \nNumber of Vectors - " << n << std::endl;
    std::cout << "Size of Vectors - " << m << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << "[" << i << "][" << j  << vectors[i][j] << " |";
		}
		std::cout << std::endl;
	}
} //---printMatrix---

/*

iaMatrix multipl2Matrix(const iaMatrix& MA, const iaMatrix& MB) { // Multiplies two matrices

    return 0;
} //---multipl2Matrix---

iaMatrix matrixAdditions(const iaMatrix& otherMatrix){ // Adds two matrices
    return 0;

} //---matrixAdditions---

iaMatrix transpose() const { // Transposes the matrix
    return 0;
} //---transpose---

iaMatrix scalarMultiply(double scalar) const { // Multiplies the matrix by a scalar
    return 0;
} //---scalarMultiply---

iaMatrix matrixSubtraction(const iaMatrix& otherMatrix) const { // Subtracts two matrices
    return 0;
} //---matrixSubtraction--

double determinant() const { // Calculates the determinant of the matrix
    return 0;
} //---determinant---

iaMatrix inverse() const { // Calculates the inverse of the matrix
    return 0;
} //---inverse---
 

iaMatrix iaMatrix::operator+(const iaMatrix& otherMatrix) const {
    if ((this->m != otherMatrix.m) && (this->n != otherMatrix.n)) {
        throw std::invalid_argument("Vectors must be of the same size for addition.");
    }
    
    iaMatrix Matrixresult(this->m, this->n); // Create a new vector for the result
    for (int i = 0; i < this->m; i++) {
        for (int j = 0; j < this->n; j++) {
            Matrixresult.vectors[i][j] = this->vectors[i][j] + otherMatrix.vectors[i][j];
        }
        //       result.value[j] = this->value[j] + otherVector.value[j]; // Add corresponding elements
        //   }
    }
    return Matrixresult; // Return the resulting vector
}
    
iaMatrix iaMatrix::operator-(const iaMatrix& otherMatrix) const {
        if ((this->m != otherMatrix.m) && (this->n != otherMatrix.n)) {
            throw std::invalid_argument("Vectors must be of the same size for addition.");
        }
        iaMatrix Matrixresult(this->m, this->n);
        for (int i = 0; i < this->m; i++)
            for (int j = 0; j < this->n; j++) {
                Matrixresult.vector[i][j] = this->vectors[i][j] - otherMatrix.vectors[i][j];
            }
        
        
        return Matrixresult;
    }
    
   
    iaMatrix iaMatrix::operator*(double a) const {
        iaMatrix Matrixresult(this->m, this->n);
        for (int i = 0; i < this->m; i++) {
            for (int j=0; j < this->n; j++) {
                Matrixresult.vector[i][j] = this->vector[i][j] * a;
            }
        }
        return Matrixresult;
    }
/*
    iaMatrix iaMatrix::operator*(<#const iaMatrix &otherMatrix#>) const {
        if (this->n != otherMatrix.n) {
            trow std::invalid_argument("--");
        }
        iaMatrix Matrixresult(this->n, otherMatrix.m);
        
        for (i = 0; i < this->n; i++)
            for (j =0; j < otherMatrix.m; j++) {
              //  Matrixresult.vector[i][j] =
                
            /*
             
             C[i][j] = A[i][1] * B[1][j] + A[i][2] * B[2][j]
             
             A(3x2)
             | 1  2 |
             | 3  4 |
             | 5  6 |
             
             B(2x4)
             | 7  8  9  10 |
             | 11 12 13 14 |
             
             
             
             i 0-> 2; j 0 -> 3
             
             i = 0;
             j = 0
             C[0][0] = (1[ij] * 7[ij]) + (2[ik] * 11[ki]) = 7 + 22 = 29 ]
             j = 1
             C[0][1] = (1[ik] * 8[ij]) + (2[ik] * 12[kj]) = 8 + 24 = 32 ]
             j =2
             C[0][2] = (1[00] * 9[20]) + (2[01] * 13[12]) = 9 + 26 = 35 ]
             j = 3
             C[0][3] = (1[00] * 10[03]) + (2[01 * 14[13]) = 10 + 28 = 38 ]
             i = 1
             j = 0
             C[1][0] = (3[10] * 7[00]) + (4[11] * 11[10]) = 21 + 44 = 65 ]
             j = 1
             C[1][1] = (3[10] * 8[01]) + (4[11] * 12[11]) = 24 + 48 = 72 ]
             j = 2
             C[1][2] = (3[10] * 9[02]) + (4[11] * 13[12]) = 27 + 52 = 79 ]
             j = 3
             C[1][3] = (3[10] * 10[03]) + (4[11] * 14[13]) = 30 + 56 = 86 ]
             i = 2
             j = 0
             C[2][0] = (5[20] * 7[00]) + (6[21] * 11[10]) = 35 + 66 = 101 ]
             j = 1
             C[2][1] = (5[20] * 8[01]) + (6[21] * 12[11]) = 40 + 72 = 112 ]
             j = 2
             C[2][2] = (5[20] * 9[02]) + (6[21] * 13[12]) = 45 + 78 = 123 ]
             j = 3
             C[2][3] = (5[20] * 10[03]) + (6[21] * 14[13]) = 50 + 84 = 134 ]
             
             
             
             
             C(3x4)
             | 29  32  35  38  |
        
             | 65  72  79  86  |
             
             | 101 112 123 134 |
             */
            }
        
        
        /*
        int m = this->m, n = this->n, no = otherMatrix.m, p = otherMatrix.n, k = p;
        if (no != n) {
        }
        for (i = 0; i < m; i++)
            for (kr = 0; kr < p; kr++) {}*/
        
        
        /*
        
        if (this->n != otherMatrix.m) {
            throw std::invalid_argument("Vectors must be of the same size for addition.");
        }
        iaMatrix Matrixresult(this->m, other.n);
        for (i = 0; i < Matrixresult.; <#increment#>) {
            <#statements#>
        }
        
    }

/*
iaMatrix _2matrixAdditions(iaMatrix MA,iaMatrix MB) {
	int Na, Nb, Ma, Mb;
	Na = MA.numberOfVectors();
	Nb =MB.numberOfVectors();
	Ma =MA.sizeOfVectors();
	Mb = MB.sizeOfVectors();
	iaMatrix MC;
	for (int i = 0; i < ; i++) {
		for (int j = 0; j< )
	}


	cout << "additions\n";
	return MC
}

iaMatrix multipl2Matrix(iaMatrix MA,iaMatrix MB) {
	cout << "***\n";
	return 0;
}
*/

