class temperature_converter:
    conversion_factor = 9 / 5

    def __init__(self,celsius):
        self.celsius = celsius

    def to_fahrenheit(self):
        return (self.celsius * self.conversion_factor)
    
    @classmethod
    def set_convesionfactor(cls,factor):
        cls.conversion_factor = factor
    
    @staticmethod
    def convert_to_ferh(celsius):
        return (celsius* 9/5) + 32

# Instance method
temp=temperature_converter(25)
print(temp.to_fahrenheit())
# Class method
temp.set_convesionfactor(2)
print(temp.to_fahrenheit())
# Static method
print(temp.convert_to_ferh(25))

