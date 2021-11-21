/**
 * This Class is a helper class for the History data points in database.
 * It gives the frame for a History data point.
 */

class History {
  String id;
  DateTime creationDate;
  int duration;

  History({
    required this.id,
    required this.creationDate,
    required this.duration,
  });

  int getMinutes() {
    return duration ~/ 60;
  }

  int getSeconds() {
    return duration % 60;
  }

  Object toJson() {
    return {
      'id': id,
      'duration': duration,
    };
  }

  History.fromJson(Map<String, dynamic> json)
      : id = json['id'],
        creationDate = DateTime.parse(json['creationDate']),
        duration = json['duration'];
}
