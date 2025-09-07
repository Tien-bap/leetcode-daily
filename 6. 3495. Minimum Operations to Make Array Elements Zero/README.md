Thử thách hard đầu tiên
Bài này yêu cầu: chọn số trong [l, r] sau đó đem nó đi floor(.../4). Số lần chọn ít nhất để cho tất cả trở về 0
Nhận thấy có thể chia đoạn này thành nhiều đoạn nhỏ có cùng floor(log4(..)) : có cùng số lần chia 4 thành 0
ta có thể tính đươc k (số bậc tối thiểu và tối đa)=> min_k = floor(log4(l)) -> max_k = floor(log4(r))
=> ta duyệt trên từng bậc k
tại k
start = max(l, 4^k) ; luôn đảm bảo l là vị trí biên trai
end = min(r, 4^(k+1) -1); luôn đảm bảo end ko vượt qua r
cnt += (end - start + 1)*(k+1)

=> duyệt hết k => (cnt+1)/2;
