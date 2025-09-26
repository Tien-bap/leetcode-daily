Bài này tìm độ dài cạnh tam giác thỏa mãn
- độ dài 3 cạnh của tam giác bất kỳ thì 2 cạnh bất kỳ luôn lớn hơn cạnh còn lại

Dùng kỹ thuật 2 con trỏ để duyệt mảng
  - sort mảng giảm dần
  - duyệt k từ đầu mảng đến cuối mảng, từ phần tử lớn nhất
  - con trỏ l duyệt từ k+1
  - con trỏ r duyệt từ cuối mảng
  - nếu cạnh l + cạnh r > cạnh k (vì k là lớn nhất và r là nhỏ nhất) => số tam giác = r - l, sau đó tăng l lên
  - ngược lại giảm r xuống
