import sys
import os 

file_list = [os.path.join("Sounding_Sensors", f'RAWDATA{i}.BIN') for i in range(0, 39)]
file_list_csv = [os.path.join("Sounding_Sensors", f'RAWDATA{i}.CSV') for i in range(0, 39)]

print(file_list)

for file in file_list: 
  if not os.path.exists(file):
    print(f"File {file} does not exist, skipping.")
    continue

  print(f"Processing file: {file}")
  os.system(f'python ConvertBin.py "{file}"')

with open('merged_output.csv', 'w') as fout:
  header_written = False

  for csv_file in file_list_csv:
    if not os.path.exists(csv_file):
      print(f"CSV file {csv_file} does not exist, skipping.")
      continue

    print(f"Merging file: {csv_file}")
    with open(csv_file, 'r') as fin:
      lines = fin.readlines()
      if not header_written:
        fout.write(lines[0])  # Write header only once
        header_written = True
      fout.writelines(lines[1:])  # Skip header in subsequent files