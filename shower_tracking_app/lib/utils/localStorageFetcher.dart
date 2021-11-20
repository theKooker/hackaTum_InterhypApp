import 'package:shower_tracking_app/data/UserTiming.dart';
import 'package:shower_tracking_app/utils/AppSharePreferences.dart';

class LocalStorageFetcher {
  static List<UserTiming> fetchLocalStorage() {
    List<UserTiming> list = [];
    AppSharePreferences().getUserTiming().then((value) => {
        for (var element in value) {
          list.add(UserTiming.fromString(element))
        }
    });
    return list;
  }
}