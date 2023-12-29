/*

- Hệ thống phải có khả năng đọc tín hiệu từ SW1 để nhận biết trạng thái có người ngồi trong ô-tô hay không. Nếu SW1 được bật, hệ thống sẽ xác định có người ngồi, ngược lại hệ thống sẽ xác định không có người ngồi.
- Hệ thống phải có khả năng đọc tín hiệu từ SW2 để nhận biết trạng thái thắt dây an toàn. Nếu SW2 được bật, hệ thống sẽ xác định dây an toàn đã được thắt, ngược lại hệ thống sẽ xác định dây an toàn chưa được thắt.
- Hệ thống phải có khả năng ghi tín hiệu ra Green LED thay cho buzzer cảnh báo nếu có người ngồi vào ô-tô nhưng không thắt dây an toàn sau một khoảng thời gian cho trước.
- Hệ thống phải có khả năng ghi tín hiệu ra màn hình LCD để hiển thị trạng thái của hệ thống hoặc đưa ra các chỉ dẫn người lái về việc thắt dây an toàn. Các trạng thái và chỉ dẫn bao gồm:
    - “Welcome”: khi hệ thống khởi động
    - “No one in the car”: khi hệ thống nhận biết không có người ngồi trong ô-tô
    - “Please fasten your seat belt”: khi hệ thống nhận biết có người ngồi trong ô-tô nhưng chưa thắt dây an toàn
    - “Seat belt fastened”: khi hệ thống nhận biết có người ngồi trong ô-tô và đã thắt dây an toàn
    - “Warning: seat belt not fastened”: khi hệ thống phát ra cảnh báo buzzer sau một khoảng thời gian cho trước từ lúc người sử dụng ngồi vào ô-tô nhưng không thắt dây an toàn

*/

#include "MKL46Z4.h"
#include "sensor.h"
#include "LCD.h"


/*Main code*/
//int main()
//{
//    int carSeatOccupiedState = 0;
//    int seatbeltFastenedState = 0;
//    int sensingTime = 10000;
    
    /*Start the alarm system*/
//    initSystem();
//    startAlarm();
//    while (1 == 1)
//    {
//        /*Perform sensing & actions*/
//        if (senseDriverIn() == 1)
//        {
//            /*Whenever the driver is in*/
//            carSeatOccupiedState = senseDriverIn();
//            
              /*Alert the driver to quickly fasten the seatbelt*/
//            alertDriverIn();
            
            /*Continuously listen to seatbelt fastening status and alert periodically*/
//            while (verifySeatbeltStatus() != 1)
//            {
//                alertDriverAsync(sensingTime / 1);
//            }
            
            /*Whenever the seatbelt is fastened*/
//            seatbeltFastenedState = verifySeatbeltStatus();
            
            /*Whenever the seatbelt is unfastended*/
//            while (verifySeatbeltStatus() == 1)
//            {
//                seatbeltFastenedState = verifySeatbeltStatus();
//            }
//        }
//        if (senseDriverOut() == 0)
//        {
            /*Whenever the driver is being out*/
//            alertDriverOut();
            /*Whenever the driver is out*/
//            carSeatOccupiedState = 0;
//        }
//    };
//};

int main()
{
    initLCD();
    setLCD(1,1);
};