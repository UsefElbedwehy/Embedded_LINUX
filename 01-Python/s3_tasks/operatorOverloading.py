'''class point:
    def __init__(self,x_coordinate,y_coordinate):
        self.x_coordinate = x_coordinate
        self.y_coordinate = y_coordinate

    def __add__(self,point_ov):
        return point((self.x_coordinate + point_ov.x_coordinate) , (self.y_coordinate + point_ov.y_coordinate))

point1 = point(2,3)
point2 = point(8,6)
point3 = point1 + point2

print(point3.x_coordinate)
print(point3.y_coordinate)'''
class flat():
    def __init__(self , area=0 , number_of_rooms=0):
        self.area = area
        self.number_of_rooms = number_of_rooms

    def __add__(self,flat_ov):
        new_flat = flat()
        new_flat.area = self.area + flat_ov.area
        new_flat.number_of_rooms = self.number_of_rooms + flat_ov.number_of_rooms
        return new_flat

myflat = flat(140,3)
neighbour_flat = flat(150,2)

my_new_flat = myflat + neighbour_flat

print(my_new_flat.number_of_rooms)
