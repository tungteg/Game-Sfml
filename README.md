I, **Hướng dẫn cài đặt thư viện SFML TRÊN DEV C++**
 1. Mở dev c++, trên thanh công cụ chọn Project -> chọn Project Options
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
 1. Chức năng lưu lại điểm cao (High Score)
 2. Chức năng tùy chọn (Option)
  1. Thay đổi màu sắc của rắn (Skin): có 4 màu sắc của rắn, thay đổi phụ thuộc vào sở thích của người chơi.
  2. Thay đổi chế độ chơi (Game Type): có 2 chế độ chơi khác nhau
     1. Chế độ cổ điển (Classic): không có tường xung quanh, rắn có thể xuyên qua tường và chui lại từ đầu đối diện.
     2. Chế độ hiện đại (Modern): có tường bao quanh, rắn khi lao vào tường sẽ bị chết.
  3. Thay đổi tốc độ của rắn (Level): có 5 level khác nhau, level càng cao tốc độ của rắn càng tăng
*(chế độ chơi càng khó thì giá trị điểm của mỗi quả cherry càng tăng -max 20, min 5-)*
  
