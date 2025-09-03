B1
+ điểm nằm bên trái phải ở trên hoặc bằng điểm bên phải
+ sort tất cả các phần tử trong mảng sao phần tử i luôn nằm bên trái phần tử i + 1
+ trong trường hợp có 2 điểm cùng giá trị x thì sort theo y lớn tới bé
=> ta được mảng các điểm theo trục tọa độ OX (cùng x thì y lớn hơn đứng trước)

B2
+ duyệt hết mảng (i->pointsSize)
+ so sánh điểm i với các điểm phía sau (j = i+1 -> poinsSize)
+ nếu i.y > j.y
    - duyệt các điểm nằm giữa i và j
    - nếu a năm giữa i và j && a.y <= i.y && a.y >= j.y  ==> flase
    - ngược lại ko có điểm nào xem giữa hình chữu nhật đó thì ==> true
+ biến đếm += 1 nếu check == true
+ trả về kết quả là biến đếm;
