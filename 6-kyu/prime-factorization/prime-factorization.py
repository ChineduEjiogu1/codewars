class PrimeFactorizer:
    def __init__(self, number):
        # store number
         self.number = number
​
    @property  
    def factor(self):
        
        current_number = self.number
        prime_factors = {}
        
        while current_number % 2 == 0:
            prime_factors[2] = prime_factors.get(2, 0) + 1
            current_number //= 2
        
        i = 3
            
        while i * i <= current_number:
            while current_number % i == 0:
                prime_factors[i] = prime_factors.get(i, 0) + 1
                current_number //= i
            i += 2
            
        if current_number > 1:
            prime_factors[current_number] = prime_factors.get(current_number, 0) + 1
            
        return prime_factors