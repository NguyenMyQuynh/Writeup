# Write up challenge Local File Inclusion - Double encoding


Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/Local-File-Inclusion-Double-encoding)<br>
</br>

Để ý hint challenge yêu cầu tìm mật khẩu trong source files, tại đây ta có thể nghĩ ngay đến php-filters.
<br>Php-filters có thể được sử dụng để xem source files cục bộ máy chủ với output là base64 với cú pháp: `vuln.php?page=php://filter/convert.base64-encode/resource=filepath`

<br>Truy cập challenge ta thấy có 3 trang Home CV Contact với url thay đổi tương ứng mỗi khi nhấp vào từng trang:

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

Thử với basic attack:

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

Không thành công! Để ý tên challenge có đề cập đến double encode. OK thử bypass cơ chế detect bằng cách encode 2 lần 

<img src="./img/6.png" alt="normal_acc_TRAbID"/>

<br>

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

Thành công vượt qua và ta từ lỗi nhận được ta biết được thêm code có dử dụng hàm include và tham số đầu vào sẽ tự động được nối với `.inc.php` vào phía sau.

<img src="./img/8.png" alt="normal_acc_TRAbID"/>

Như đã phân tích ban đầu, thử áp dụng php-filters để xem source trang home:

        index.php?page=php://filter/convert.base64-encode/resource=home

Nhớ là encode 2 lần như đã phân tích, payload cuối cùng:

        index.php?page=php:%252f%252ffilter%252fconvert%252ebase64-encode%252fresource=home

<img src="./img/9.png" alt="normal_acc_TRAbID"/>


Decode base64 output trang home vừa nhận được,ta thấy được nội dung trang home. Đọc code ta không thấy `user` và password đâu cả. Tuy nhiên để ý ta thấy có câu lệnh ` include("conf.inc.php");` ở phần đầu, có thể pass có ở đây.

<img src="./img/10.png" alt="normal_acc_TRAbID"/>

<br>OK, bây giờ ta sẽ tiến hành áp dụng php-filters để xem source file conf.inc.php(chú ý hậu tố .inc.php sẽ tự động được thêm vào nên ta chỉ cần tên file là conf):

        index.php?page=php://filter/convert.base64-encode/resource=conf

Payload cuối cùng:

        index.php?page=php:%252f%252ffilter%252fconvert%252ebase64-encode%252fresource=conf

<img src="./img/11.png" alt="normal_acc_TRAbID"/>

Đã thấy flag!

<img src="./img/12.png" alt="normal_acc_TRAbID"/>


Submit flag thành công!

<img src="./img/13.png" height=350 alt="normal_acc_TRAbID"/>

<br>

> **Flag:** Th1sIsTh3Fl4g!