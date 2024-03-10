class Complex:
    def __init__(self, real=0, imag=0):
        self.real = real
        self.imag = imag


    def __add__(self, other):
        return Complex(self.real + other.real, self.imag + other.imag)


    def __mul__(self, other):
        return Complex(self.real * other.real - self.imag * other.imag, self.real * other.imag + self.imag * other.real)


    def __str__(self):
        if self.imag >= 0:
            return f"{self.real}+{self.imag}i"
        else:
            return f"{self.real}{self.imag}i"

z1 = Complex(0)
z2 = Complex(1, 2)
z3 = z1 + z2
z4 = z1 * z2

print(z1) # 0+0i
print(z2) # 1+2i
print(z3) # 1+2i
print(z4) # 0+0i
