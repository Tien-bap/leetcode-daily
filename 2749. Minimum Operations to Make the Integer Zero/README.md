Thử thách này yêu cầu tìm số lần thực hiện phép toán ít (-1 nếu ko tìm được) trong phạm vi 0<=k<=60
Phép toán: num1 - k*(2^i + num2 ) = 0; với i bất kỳ;
=> num1 - k*2^i - k*num2 = 0
Đặt num = num1 - k*num2  => num = k*2^i => bài toán trở thành phân tích 1 số nguyên thành nhị phân

* num >= 0 vì k*2^i >= với mọi k và i
* num >= k vì giá trị của 1 số luôn lớn hơn hoặc bằng số lượng bit 1 của nó

=> tìm số bit nhị phân là 1 của num => count 
* count <= k => k
