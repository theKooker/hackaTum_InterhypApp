import 'package:firebase_auth/firebase_auth.dart';

class AccountData {
  static Future<bool> isLoggedIn() async {
    return await FirebaseAuth.instance.currentUser() != null;
  }

  static Future<String> getUserId() async {
    return (await FirebaseAuth.instance.currentUser()).uid;
  }

  static Future<String> getUserName() async {
    return (await FirebaseAuth.instance.currentUser()).displayName;
  }
}