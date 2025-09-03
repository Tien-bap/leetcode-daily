1. giải pháp 1
  - delta = (passi + 1/totali +1) - (passi/totali) tỉ lệ tăng nếu thêm 1 hs giỏi vào lớp
  - sắp xếp các lớp học theo delta giảm dần
  - phân bổ học sinh giỏi +1 vào lớp đầu tiên
  - lặp lại cho đến khi hết học sinh giỏi
## code này có độ phức tạp lên đến O(nlogn) + O(n * E) với E là vòng while

2. giải pháp 2
- sử dụng heap để lưu trữ các lớp học và tỉ lệ tăng của chúng
- mỗi lần phân bổ học sinh giỏi, ta sẽ lấy lớp có tỉ lệ tăng lớn nhất để phân bổ
- độ phức tạp của giải pháp này là O(nlogn) cho việc sắp xếp và O(Elogn) cho việc phân bổ học sinh giỏi
