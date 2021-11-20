import 'dart:convert';

class UserTiming {
  String date;
  String time;
  UserTiming({required this.date, required this.time});
  Map toJson() => {
        'date': date,
        'time': time,
      };
  static UserTiming fromString(String str) {
      var jsonData = json.decode(str);
      return UserTiming(date: jsonData['date'], time: jsonData['time']);
  }
}
