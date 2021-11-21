import 'package:flutter/material.dart';
import 'package:shower_tracking_app/components/custom_card.dart';
import 'package:shower_tracking_app/data/user_timing.dart';
import 'package:shower_tracking_app/utils/local_storage_fetcher.dart';

class HistoryTable extends StatefulWidget {
  const HistoryTable({Key? key}) : super(key: key);

  @override
  State<HistoryTable> createState() => _HistoryTableState();
}

class _HistoryTableState extends State<HistoryTable> {
  @override
  Widget build(BuildContext context) {
    var children = <Widget>[
      _card(UserTiming(
        day: '12',
        month: '10',
        year: '2021',
        hour: '9',
        minute: '00',
        time: '4:00',
      )),
      _card(UserTiming(
        day: '11',
        month: '10',
        year: '2021',
        hour: '8',
        minute: '00',
        time: '4:00',
      )),
      _card(UserTiming(
        day: '10',
        month: '10',
        year: '2021',
        hour: '18',
        minute: '00',
        time: '4:00',
      )),
      _card(UserTiming(
        day: '9',
        month: '10',
        year: '2021',
        hour: '18',
        minute: '00',
        time: '4:00',
      )),
      _card(UserTiming(
        day: '8',
        month: '10',
        year: '2021',
        hour: '18',
        minute: '00',
        time: '4:00',
      )),
    ];

    return Column(
      children: children,
    );
  }

  Widget _card(UserTiming item) {
    var date = item.day + "." + item.month + "." + item.year;
    var time = item.hour + ":" + item.minute;

    var duration = item.time;

    return CustomCard(
      child: Row(
        children: [
          Container(
            padding: EdgeInsets.all(8),
            decoration: BoxDecoration(
              borderRadius: BorderRadius.circular(15),
              color: Colors.blue,
            ),
            child: Center(
              child: Column(
                children: [
                  Text(
                    date,
                    style: const TextStyle(
                      color: Colors.white,
                    ),
                  ),
                  Text(
                    time,
                    style: const TextStyle(
                      color: Colors.white,
                    ),
                  ),
                ],
              ),
            ),
          ),
          Expanded(
            child: Container(
              padding: EdgeInsets.all(8),
              child: Center(
                child: Column(
                  children: [
                    const Text(
                      "Time",
                      style: TextStyle(
                        color: Colors.white,
                        fontSize: 10,
                      ),
                    ),
                    Text(
                      duration,
                      style: const TextStyle(
                        color: Colors.white,
                        fontSize: 20,
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ),
          Expanded(
            child: Container(
              padding: EdgeInsets.all(8),
              child: Center(
                child: Column(
                  children: [
                    const Text(
                      "Water",
                      style: TextStyle(
                        color: Colors.white,
                        fontSize: 10,
                      ),
                    ),
                    Text(
                      "2.5 l",
                      style: const TextStyle(
                        color: Colors.white,
                        fontSize: 20,
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ),
          Expanded(
            child: Container(
              padding: EdgeInsets.all(8),
              child: Center(
                child: Column(
                  children: [
                    const Text(
                      "Energy",
                      style: TextStyle(
                        color: Colors.white,
                        fontSize: 10,
                      ),
                    ),
                    Text(
                      "2 kJ",
                      style: const TextStyle(
                        color: Colors.white,
                        fontSize: 20,
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ),
        ],
      ),
    );
  }
}
