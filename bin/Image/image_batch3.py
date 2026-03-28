from PIL import Image
import os

input_folder = R"./"
output_folder = R"./img20"
filename = "Setting.png"

input_path = os.path.join(input_folder, filename)

os.makedirs(output_folder, exist_ok=True)

try:
    with Image.open(input_path) as img:
        img = img.convert('RGBA')
        datas = img.getdata()
        new_data = []

        target_r, target_g, target_b = 255, 255, 255
        tolerance = 70

        for item in datas:
            r, g, b, a = item

            diff_r = abs(r - target_r)
            diff_g = abs(g - target_g)
            diff_b = abs(b - target_b)

            if (diff_r < tolerance and diff_g < tolerance and diff_b < tolerance) or a < 250:
                new_data.append((0x0e, 0x1d, 0x69, 255))
            else:
                new_data.append(item)

        img.putdata(new_data)
        output_path = os.path.join(output_folder, filename)
        img.save(output_path, "PNG")
        print(f"处理完成！已保存至: {output_path}")

except Exception as e:
    print(f"处理失败: {e}")