import os
import platform

def copy_all_text_from_directory(directory_path):
    all_text = ""
    for root, dirs, files in os.walk(directory_path):
        for file in files:
            if file.endswith(('.cpp', '.h')):  # Only copy C++ source and header files
                file_path = os.path.join(root, file)
                with open(file_path, 'r') as f:
                    all_text += f"\n\n// Contents of {file_path}:\n"
                    all_text += f.read()
    return all_text

def save_to_file(output_path, content):
    with open(output_path, 'w') as f:
        f.write(content)

def copy_to_clipboard(output_path):
    system_platform = platform.system()
    if system_platform == "Darwin":  # macOS
        os.system(f"cat {output_path} | pbcopy")
    elif system_platform == "Linux":
        os.system(f"cat {output_path} | xclip -selection clipboard")
    elif system_platform == "Windows":
        os.system(f"type {output_path} | clip")
    else:
        print("Clipboard copy is not supported on this platform.")

if __name__ == "__main__":
    directory = "practical_3"
    output_file = "output.txt"
    
    combined_text = copy_all_text_from_directory(directory)
    save_to_file(output_file, combined_text)
    
    print(f"All text has been copied and saved to {output_file}")
    copy_to_clipboard(output_file)
    print("The content has also been copied to your clipboard.")
