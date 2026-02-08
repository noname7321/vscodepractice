import pdfplumber
with pdfplumber.open("经济学人索德兰特刊.pdf") as pdf:
    for page in pdf.pages:#遍历每一页
        text = page.extract_text()
        print(text)
        print(f'------------第{page.page_number}页结束-----------')

from pdf2docx import Converter

src = "经济学人索德兰特刊.pdf"
dst = "out.docx"
cv = Converter(src)
cv.convert(dst)
cv.close()
print("Saved", dst)