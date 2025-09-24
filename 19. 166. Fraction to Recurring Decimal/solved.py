class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        seen = {}
        result = []

        if numerator == 0: return "0"

        if (numerator < 0) ^ (denominator < 0): result.append("-")
        numerator = abs(numerator)
        denominator = abs(denominator)

        result.append(str(numerator // denominator))
        rem = numerator % denominator
        if rem == 0: return "".join(result)
        result.append(".")
        
        while rem != 0:
            if rem in seen:
                result.insert(seen[rem], "(")
                result.append(")")
                break
            seen[rem] = len(result)
            rem*=10
            result.append(str(rem // denominator))
            rem = rem % denominator
        
        return "".join(result)

        
