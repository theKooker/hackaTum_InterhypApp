import 'dart:async';
import 'dart:io';
import 'package:shower_tracking_app/data/user_timing.dart';
import 'package:shower_tracking_app/utils/app_share_preferences.dart';
import 'package:shower_tracking_app/utils/local_storage_fetcher.dart';
import 'package:stop_watch_timer/stop_watch_timer.dart'; // Import stop_watch_timer

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class RecordingPage extends StatefulWidget {
  const RecordingPage({Key? key}) : super(key: key);

  @override
  _RecordingPageState createState() => _RecordingPageState();
}

class _RecordingPageState extends State<RecordingPage> {
  final StopWatchTimer _stopWatchTimer = StopWatchTimer();
  bool _startTime = false;
  var button_string = "assets/images/Design_startLifted.png";
  @override
  void dispose() {
    super.dispose();
    _stopWatchTimer.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(
        children: [
          Image.asset("assets/images/Design_BigBackground.png",
              height: MediaQuery.of(context).size.height, fit: BoxFit.fill),
          SingleChildScrollView(
            physics: const NeverScrollableScrollPhysics(),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Center(
                  child: Image.asset("assets/images/Design_shower.png"),
                ),
                Center(
                  child: Image.asset(
                      "assets/images/Design_waterStreamSeamless.png",
                      fit: BoxFit.none),
                ),
              ],
            ),
          ),
          Positioned(
            bottom: -20,
            child: Opacity(
              opacity: 0.5,
              child: Image.asset(
                "assets/images/BigBubbles_BigBubbles.png",
                width: MediaQuery.of(context).size.width,
                fit: BoxFit.fill,
              ),
            ),
          ),
          Positioned(
            right: 0,
            bottom: 250,
            child: Image.asset(
              "assets/images/SmallBubble_SmallBubble.png",
              width: 150,
            ),
          ),
          Positioned(
            right: 50,
            top: 80,
            child: Image.asset(
              "assets/images/SmallBubble_SmallBubble.png",
              width: 40,
            ),
          ),
          Positioned(
            top: 80,
            left: 10,
            child: Image.asset(
              "assets/images/SmallBubble_SmallBubble.png",
              width: 250,
            ),
          ),
          Positioned(
            bottom: 150,
            left: -70,
            child: Image.asset(
              "assets/images/SmallBubble_SmallBubble.png",
              width: 200,
            ),
          ),
          Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Center(
                child: Container(
                  height: 0,
                ),
              ),
              Center(
                child: Container(
                  height: 0,
                ),
              ),
              Center(
                child: Container(
                  height: 0,
                ),
              ),
              Stack(
                children: [
                  Center(
                      child: GestureDetector(
                    onTapDown: (value) {
                      setState(() {
                        if (button_string ==
                            "assets/images/Design_startLifted.png") {
                          _stopWatchTimer.onExecute.add(StopWatchExecute.start);
                          button_string =
                              "assets/images/Design_startPushed.png";
                        } else {
                          _stopWatchTimer.onExecute.add(StopWatchExecute.reset);
                          UserTiming timing = UserTiming(
                              day: DateTime.now().day.toString(),
                              month: DateTime.now().month.toString(),
                              year: DateTime.now().year.toString(),
                              hour: DateTime.now().hour.toString(),
                              minute: DateTime.now().minute.toString(),
                              time:
                                  _stopWatchTimer.secondTime.value.toString());
                          AppSharePreferences().addUserTiming(timing);
                          LocalStorageFetcher.fetchLocalStorage();
                          button_string = "assets/images/Design_redPushed.png";
                        }
                        _startTime = !_startTime;
                      });
                    },
                    onTapUp: (value) {
                      setState(() {
                        if (button_string ==
                            "assets/images/Design_startPushed.png") {
                          button_string = "assets/images/Design_redLifted.png";
                        } else {
                          button_string =
                              "assets/images/Design_startLifted.png";
                        }
                      });
                    },
                    child: Column(
                      children: [
                        Stack(
                          children: [
                            Image.asset(button_string, height: 100),
                            if (_startTime)
                              Positioned.fill(
                                child: Align(
                                  alignment: Alignment.center,
                                  child: StreamBuilder<int>(
                                    stream: _stopWatchTimer.rawTime,
                                    initialData: _stopWatchTimer.rawTime.value,
                                    builder: (context, snapshot) {
                                      final value = snapshot.data;
                                      final displayTime =
                                          StopWatchTimer.getDisplayTime(value!,
                                              hours: false, milliSecond: false);
                                      return Text(
                                        displayTime,
                                        style: const TextStyle(
                                            fontSize: 50,
                                            fontWeight: FontWeight.bold,
                                            color: Colors.white),
                                      );
                                    },
                                  ),
                                ),
                              ),
                          ],
                        )
                      ],
                    ),
                  )),
                ],
              )
            ],
          )
        ],
      ),
    );
  }
}
