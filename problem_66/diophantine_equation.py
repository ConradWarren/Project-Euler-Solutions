import math

def Is_Square(num):
    
    sqrt = int(math.sqrt(num))
    
    if sqrt * sqrt == num:
        return True
    else:
        return False

def Get_Convergant_Fraction(a_values, d):
    
    idx = len(a_values) - 1
    numerator = 1
    denominator = a_values[idx]
    idx -= 1
    while(idx > 0):

        numerator += a_values[idx] * denominator
        gcd = math.gcd(numerator, denominator)
        numerator //= gcd
        denominator //= gcd

        numerator, denominator = denominator, numerator
        idx -= 1
    
    numerator += denominator * a_values[0]
    gcd = math.gcd(numerator, denominator)
    numerator //= gcd
    denominator //= gcd

    if(numerator * numerator - d * denominator * denominator == 1):
        return numerator

    return -1


def Diophantine_Equation():
    
    upper_limit = 1000
    result = 0
    highest_seen = 0

    for d in range(2, upper_limit+1):
        
        if(Is_Square(d)):
            continue

        a = int(math.sqrt(d))
        numerator = -a
        denomirator = 1
        factor = 1
        a_values = [a]
        while(True):
            
            rationalized_denomirator = factor * factor * d - numerator * numerator
            factor *= denomirator
            numerator = denomirator * -numerator
            denomirator = rationalized_denomirator

            gcd = math.gcd(factor, math.gcd(numerator, denomirator))
            
            numerator //= gcd
            denomirator //= gcd
            factor //= gcd

            a = (factor * math.sqrt(d) + numerator) / denomirator
            a = int(a)
            
            numerator -= a * denomirator;

            a_values.append(a)
            fraction = Get_Convergant_Fraction(a_values, d)
            if fraction != -1:
                if fraction > highest_seen:
                    highest_seen = fraction
                    result = d
                break

    return result

print(Diophantine_Equation())
#661

