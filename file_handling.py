my_file = open("MYFILE.txt","w+")
my_file.write("This text is written in python. Python is fun")
my_file = open("MYFILE.txt", "r")
lines = my_file.readlines()
count = 0
vowel = 0
for line in lines:
    words = line.split()
    for word in words:
        if len(word) == 4:
            count+=1
    for char in line:
        if char.upper() == "A" or char.upper() == "E" or char.upper() == "I" or char.upper() == "O" or char.upper() == "U":
            vowel+=1
print("Total 4 letter words =", count)
print("Total no. of vowels =", vowel)