import 'dart:convert';

class UserTiming {
  String day;
  String month;
  String year;

  String hour;
  String minute;

  String time;

  // UserTiming({required date, required time}) {
  //   this.day = date.day.toString();
  //   this.month = date.month.toString();
  //   this.year = date.year.toString();
  //   this.hour = date.hour.toString();
  //   this.minute = date.minute.toString();
  //   this.time = time.toString();
  // }

  UserTiming({
    required this.day,
    required this.month,
    required this.year,
    required this.hour,
    required this.minute,
    required this.time,
  });

  Map<String, dynamic> toJson() => {
        "\"day\"": day,
        "\"month\"": month,
        "\"year\"": year,
        "\"hour\"": hour,
        "\"minute\"": minute,
        "\"time\"": time,
      };

  static UserTiming fromString(String str) {
    var jsonData = json.decode(str);
    return UserTiming(
      day: jsonData['day'].toString(),
      month: jsonData['month'].toString(),
      year: jsonData['year'].toString(),
      hour: jsonData['hour'].toString(),
      minute: jsonData['minute'].toString(),
      time: jsonData['time'].toString(),
    );
  }
}
