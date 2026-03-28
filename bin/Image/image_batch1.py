from PIL import Image
import os

# input_folder = R"./Image"
# output_folder = R"./Image/img2"

input_folder = R"./"
output_folder = R"./img100"

filename = "9.png"
input_path = os.path.join(input_folder, filename)

with Image.open(input_path) as img:
    img = img.convert('RGBA')
    l = 1000
    t = 1000
    r = 0
    d = 0

    for i in range(400):
        for j in range(400):
            pixel_value = img.getpixel((i, j))
            if (pixel_value[3] != 0):
                l = min(l, i)
                r = max(r, i)
                t = min(t, j)
                d = max(d, j)

    img = img.crop((l, t, r, d))
    output_path = os.path.join(output_folder, filename)
    img.save(output_path)
