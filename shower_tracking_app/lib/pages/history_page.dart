import 'package:flutter/material.dart';
import 'package:shower_tracking_app/components/statistics_graph.dart';
import 'package:shower_tracking_app/components/statistics_grid.dart';
import 'package:shower_tracking_app/components/heading.dart';

class HistoryPage extends StatefulWidget {
  const HistoryPage({Key? key}) : super(key: key);

  @override
  _HistoryPageState createState() => _HistoryPageState();
}

class _HistoryPageState extends State<HistoryPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.indigo,
      body: SafeArea(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Heading("Statistics"),
            const Padding(
              padding: EdgeInsets.only(left: 20, bottom: 5),
              child: Text(
                "Last weeks Statistics:",
                style: TextStyle(
                  fontSize: 20,
                  fontWeight: FontWeight.bold,
                  color: Colors.white,
                ),
              ),
            ),
            StatisticsGrid(),
            StatisticsGraph(),
          ],
        ),
      ),
    );
  }
}
