# Write up challenge Directory traversal


Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/Directory-traversal)<br>
</br>

Hint đề bài tìm phần ẩn bộ ảnh

<img src="./img/1.png" alt="normal_acc_TRAbID"/>

Truy cập challenge ta thấy có 5 tab   | emotes | apps | devices | categories | actions |

Bấm chọn từng tab thử thì ta thấy tương ứng với từng tab là thư mục chứa các file ảnh render lên cho người dùng xem, đồng thời ta thấy url thay đổi, có thêm tham số `?galerie=emotes`

<img src="./img/2.png" alt="normal_acc_TRAbID"/>


Tiến hành thử một attack đơn giản: `http://challenge01.root-me.org/web-serveur/ch15/ch15.php?galerie=../`
<br> Thật vậy, có lỗi Local File Inclusion!

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

Ta thấy thư mục galerie, vào xem thử: `http://challenge01.root-me.org/web-serveur/ch15/ch15.php?galerie=../galerie/`

<img src="./img/4.png" alt="normal_acc_TRAbID"/>

Ngoài các thư mục ban đầu ta thấy có thêm 1 thư mục là `86hwnX2r`. Ta Tiến hành vào xem thử, url tương ứng `http://challenge01.root-me.org/web-serveur/ch15/ch15.php?galerie=../galerie/86hwnX2r` thấy được một file khả nghi là password.txt.

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

Inspect thử ta tìm được url file password `http://challenge01.root-me.org/web-serveur/ch15/galerie/86hwnX2r/password.txt`

<img src="./img/6.png" alt="normal_acc_TRAbID"/>

Tru cập url vừa tìm được thì nhận được flag.

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

Submit thành công! 

<img src="./img/8.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** kcb$!Bx@v4Gs9Ez