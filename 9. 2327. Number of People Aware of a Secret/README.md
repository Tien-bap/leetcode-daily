Bài này khá căng với tag medium

Bài yêu cầu tìm số người nhớ được bí mật sau n ngày với delay(sau delay ngày sẽ có thể truyền bí mật) và forget(sau forget ngày sẽ quên, không thể truyền tiếp được)

Bài này tôi chọn cách dùng 1 mảng arr với n+1 phần từ để theo dõi số người được biết thêm ở ngày thứ i

biến total += arr[i-delay] - arr[i-forget] để nhận biết vào ngày thứ i, có tổng bao nhiêu người có thể truyền bí mật

=> arr[i] = total // số người tăng thêm nhờ total người có thể truyền bí mật

=> cuối cùng ta cần duyệt từ n-delay+1 -> n và + thêm total => số người biết bí mật


