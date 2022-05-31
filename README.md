I, **Hướng dẫn cài đặt thư viện SFML TRÊN DEV C++**

* File thư viện sfml đã có sẵn chỉ cần tải về và cài đặt theo hướng dẫn.

1. Mở GameSanke, trên thanh công cụ chọn Project -> chọn Project Options.
2. Chọn Parameters, trong Linker chúng ta dán 4 dòng sau vào:
     1. -lsfml-audio
     2. -lsfml-graphics
     3. -lsfml-window
     4. -lsfml-system 
 3. Chọn Directories
     1. trong Libary Directories chúng ta add đường dẫn: SFML-2.4.2\lib
     2. trong Include Directories ta add đường dẫn: SFML-2.4.2\include
 4. chọn OK, thế là xong các bước cài đặt thư viện sfml vào dev c++. Video hướng dẫn chi tiết (https://www.youtube.com/watch?v=uAd2jINKCxc).
 
II, **Mô tả chung về trò chơi, các ý tưởng chính**
* Snake Game: được xây dựng lại dựa trên game rắn săn mồi trong điện thoại nokia 1280, game dược bằng cách điều khiển chú rắn đi ăn mồi xung quannh một map, mỗi lần ăn một quả cherry rắn được dài thêm một đốt, nếu rắn cắn vào thân hoặc lao vào tường thì rắn sẽ bị chết và phải chơi lại từ đầu.
* các ý tưởng: các chế độ chơi khác nhau, các skin rắn khác nhau.

III, **Mô tả các chức năng đã cài đặt**
 * Chức năng lưu lại điểm cao (High Score).
     1. Lưu lại điểm cao nhất.
     2. điểm cao được lưu vào file *HighScore.txt*. Khi chạy game điểm trong file *HighScore.txt* sẽ được lấy ra bởi hàm *fHighScore* lưu vào *diem* trong struct *HighScore*. Nếu *_Score* lớn hơn *diem.HighScore* thì *diem.HighScore* sẽ nhận giá trị điểm mới và lưu ngược lại vào *HighScore.txt*. 
 * Chức năng tùy chọn (Option).
    1. Thay đổi màu sắc của rắn (Skin):có 4 màu sắc của rắn, dựa trên 2 màu chính là lục và hồng. Thay đổi phụ thuộc vào sở thích của người chơi.
          
    2. Thay đổi chế độ chơi (Game Type): có 2 chế độ chơi khác nhau
       1. Chế độ cổ điển (Classic): 
          1. không có tường xung quanh, rắn có thể xuyên qua tường và chui lại từ đầu đối diện.
          2. logic: khi vị trí đầu của con rắn đi vào cuối vị trí *map* thì đầu sẽ được nhận vị trí được đối diện.
       2. Chế độ hiện đại (Modern): 
          1. có tường bao quanh, rắn khi lao vào tường sẽ bị chết.
          2. logic: hàm *fEndGame* sẽ check xem rắn có đi vào tường không nếu đi vào tường thì sẽ chết.
       
    3. Thay đổi tốc độ của rắn (Level): có 5 level khác nhau, level càng cao tốc độ của rắn càng tăng.

  *(chế độ chơi càng khó thì giá trị điểm của mỗi quả cherry càng tăng -max 20, min 5-)*

*xem chi tiết tại (https://www.youtube.com/watch?v=J9A5TxFo0cY).


IV, **Các kỹ thuật lập trình được sử dụng trong chương trình**
 * Struct: sử dụng để biểu diễn vị trí rắn, quả cherry, tường, điểm cao.
 * Mảng: rắn,...
 * Nhập xuất tệp: để lưu lại điểm cao.
 * Đồ họa: thư viện sfml.
     
V, **Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình**
* Kết luận:
     1. Game đã hoàn thành được tương đối các ý tưởng bản thân đề ra.
     2. Đồ họa còn đơn giản.
     3. Thư viện đồ họa rất cần với game. Giúp tạo giao diện sinh động, tương tác với ngươi chơi tốt hơn.
     4. 
* Hướng phát triển:
     1. Chế đồ chơi: phát triển thêm nhiều chế độ chơi mới, các map mới. VD thêm tường ở giữa map, bỏ một phần tường 2 bên, kết hợp giứa chế độ classic và modern.
     2. Màu sắc của rắn (skin): phát triển thêm nhiều skin mới, bắt mắt và đẹp hơn.
     3. Thay đổi màu tường.
* Các điều tâm đắc sau khi hoàn thiện chương trình:
     1.  Biết sử dụng thư viện đồ họa SFML.
     2.  Cần tách file để quản lý code dễ hơn, code cần mạch lạc, theo hướng kể chuyện.
     3.  Sử dung paint để làm đồ họa cho game.
     4.  Hiểu được logic của game, có kể hoạch phác thảo qua về code và cách bồ chí đồ họa sao cho hợp lý.
     
 VI, **Các nguồn tham khảo**
 https://codelearn.io/sharing/huong-dan-code-game-ran-san-moi-trong-cpp
 https://www.sfml-dev.org/index.php
 https://www.youtube.com/watch?v=mLVPY_B3dRU&list=PLZd7ojlRK0byXW3dd-HnucM34JnCPyNkn
   
   






