I, **Hướng dẫn cài đặt thư viện SFML TRÊN DEV C++**
*File thư viện sfml đã có sẵn chỉ cần down git về và cái đặt theo hướng dẫn là chơi được.

1.Mở GameSanke, trên thanh công cụ chọn Project -> chọn Project Options
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
 * Chức năng tùy chọn (Option).
    1. Thay đổi màu sắc của rắn (Skin): có 4 màu sắc của rắn, thay đổi phụ thuộc vào sở thích của người chơi.
    2. Thay đổi chế độ chơi (Game Type): có 2 chế độ chơi khác nhau
       1. Chế độ cổ điển (Classic): không có tường xung quanh, rắn có thể xuyên qua tường và chui lại từ đầu đối diện.
       2. Chế độ hiện đại (Modern): có tường bao quanh, rắn khi lao vào tường sẽ bị chết.
    3. Thay đổi tốc độ của rắn (Level): có 5 level khác nhau, level càng cao tốc độ của rắn càng tăng

  *(chế độ chơi càng khó thì giá trị điểm của mỗi quả cherry càng tăng -max 20, min 5-)*

*xem chi tiết tại (https://www.youtube.com/watch?v=J9A5TxFo0cY).


IV, **Các kỹ thuật lập trình được sử dụng trong chương trình**
 1. struct: sử dụng để biểu diễn rắn, quả cherry, tường, điểm cao.
 2. mảng: rắn,...
 3. đồ họa: thư viện sfml

V, **Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình**
* Kết luận: đã hoàn thành được 80% các ý tưởng của bản thân đề ra, đồ họa chưa được đẹp.
* Hướng phát triển:
   1. Chế đồ chơi: phát triển thêm nhiều chế độ chơi mới, các map mới. VD thêm tường ở giữa map, bỏ một phần tường 2 bên, kết hợp giứa chế độ classic và modern.
   2. Màu sắc của rắn (skin): phát triển thêm nhiều skin mới, bắt mắt và đẹp hơn.
   3. Thay đổi màu tường.
* Các điều tâm đắc sau khi hoàn thiện chương trình:
   1.  biết sử dụng thư viện đồ họa SFML.
   2.  biết sắp xếp code sao cho dễ đọc và dễ hiểu.
   
   






