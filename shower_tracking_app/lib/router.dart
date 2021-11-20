import 'package:flutter/material.dart';
import 'package:shower_tracking_app/pages/history_page.dart';
import 'package:shower_tracking_app/pages/ranking_page.dart';
import 'package:shower_tracking_app/pages/recording_page.dart';
import 'package:shower_tracking_app/pages/test_page.dart';

import 'components/bottom_bar.dart';

class RouterPage extends StatefulWidget {
  const RouterPage({
    Key? key,
  }) : super(key: key);

  @override
  State<RouterPage> createState() => _RouterPageState();
}

class _RouterPageState extends State<RouterPage> {
  int _currentIndex = 0;

  @override
  Widget build(BuildContext context) {
    return _bottomNavPagination();
  }

  Scaffold _bottomNavPagination() {
    return Scaffold(
      body: Stack(children: [
        IndexedStack(
          index: _currentIndex,
          children: const [
            RecordingPage(),
            RankingPage(),
            HistoryPage(),
          ],
        ),
        BottomBar(
          index: _currentIndex,
          onChange: (value) {
            setState(() {
              _currentIndex = value;
            });
          },
          items: <BottomBarItem>[
            BottomBarItem("assets/image/Design_playIcon.png", "assets/image/Design_hamburgerIcon.png"), //Recording
            BottomBarItem("assets/image/Design_hamburgerIcon.png", "assets/image/Design_hamburgerIcon.png"), //Ranking
            BottomBarItem("assets/image/Design_hamburgerIcon.png", "assets/image/Design_hamburgerIcon.png"), //History
          ],
        ),
      ]),
    );
  }
}
