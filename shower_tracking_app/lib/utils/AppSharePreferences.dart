import 'package:shared_preferences/shared_preferences.dart';
import 'package:shower_tracking_app/data/UserTiming.dart';
import 'dart:convert';

class AppSharePreferences {
  final String _userTimings = "times_dates";

  Future<bool> addUserTiming(UserTiming userTiming) async {
    SharedPreferences preferences = await SharedPreferences.getInstance();
    var str = userTiming.toJson().toString();
    List<String>list = [];
    getUserTiming().then((value) => {list = value ,list.add(str),preferences.setStringList(_userTimings, list)});
    return true;
  }

  Future<List<String>> getUserTiming() async {
    SharedPreferences preferences = await SharedPreferences.getInstance();

    if (preferences.containsKey(_userTimings)) {
      return preferences.getStringList(_userTimings)??[];
    } else {
      return [];
    }
  }
}
