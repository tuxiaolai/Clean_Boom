import sys
from PIL import Image
import os

# os.environ._data = os.environ._create()
# --- 接收 C++ 传进来的参数 ---
# 从环境变量中获取值
# raw_value = os.getenv("CPP_DATA_VALUE")
#
# if raw_value is not None:
#     try:
#         size = int(raw_value)
#         print(f"Python_Helper: Python 接收到 C++ 的变量: {size}")
#     except ValueError:
#         print(f"Python_Helper: 错误：接收到的数据 '{raw_value}' 无法转换为整数。")
#         size = 20  # 默认值
# else:
#     print("Python_Helper: 警告: 未接收到环境变量 CPP_DATA_VALUE，使用默认值")
#     size = 20
#
# print(f"Python_Helper: 最终使用的 size 值为: {size}")

size = 50

# input_folder = R"./Image/img2"
# output_folder = R"./Image/img20"

input_folder = R"./img100"
output_folder = R"./img50"

for filename in os.listdir(input_folder):
    if filename.endswith('.png'):
        input_path = os.path.join(input_folder, filename)

        with Image.open(input_path) as img:
            img = img.resize((size, size))

            output_path = os.path.join(output_folder, filename)
            img.save(output_path)
