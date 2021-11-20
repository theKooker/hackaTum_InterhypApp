import 'dart:math';

import 'package:fl_chart/fl_chart.dart';
import 'package:flutter/material.dart';
import 'package:shower_tracking_app/components/custom_card.dart';

class StatisticsGraph extends StatelessWidget {
  final _textStyle = const TextStyle(
    fontSize: 20,
    color: Colors.white,
  );

  var weekdays = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'];

  @override
  Widget build(BuildContext context) {
    return CustomCard(
      child: Padding(
        padding: const EdgeInsets.only(
          bottom: 15,
          left: 15,
          right: 15,
          top: 40,
        ),
        child: AspectRatio(
          aspectRatio: 1.7,
          child: BarChart(
            BarChartData(
              alignment: BarChartAlignment.spaceAround,
              barGroups: barGroups(),
              borderData: borderData(),
              titlesData: titlesData(),
              barTouchData: barTouchData(),
              gridData: FlGridData(show: false),
            ),
          ),
        ),
      ),
    );
  }

  BarTouchData barTouchData() {
    return BarTouchData(
      enabled: false,
      touchTooltipData: BarTouchTooltipData(
        tooltipBgColor: Colors.transparent,
        tooltipPadding: const EdgeInsets.all(0),
        tooltipMargin: 8,
        getTooltipItem: (
          BarChartGroupData group,
          int groupIndex,
          BarChartRodData rod,
          int rodIndex,
        ) {
          return BarTooltipItem(
            rod.y.round().toString(),
            _textStyle,
          );
        },
      ),
    );
  }

  FlTitlesData titlesData() {
    return FlTitlesData(
      show: true,
      rightTitles: SideTitles(showTitles: false),
      leftTitles: SideTitles(showTitles: false),
      topTitles: SideTitles(showTitles: false),
      bottomTitles: SideTitles(
        showTitles: true,
        getTextStyles: (c, s) => _textStyle,
        margin: 8,
        getTitles: (double value) {
          return weekdays[value.toInt()];
        },
      ),
    );
  }

  FlBorderData borderData() {
    return FlBorderData(
      border: const Border(
        top: BorderSide.none,
        right: BorderSide.none,
        left: BorderSide.none,
        bottom: BorderSide.none,
      ),
    );
  }

  List<BarChartGroupData> barGroups() {
    List<BarChartGroupData> barChartGroups = [];

    var rng = new Random();

    for (var i in weekdays) {
      barChartGroups.add(
        BarChartGroupData(
          x: weekdays.indexOf(i),
          barRods: [
            BarChartRodData(
              y: rng.nextDouble() * 12,
              colors: [Colors.blue, Colors.blue.shade50],
              width: 18,
            ),
          ],
          showingTooltipIndicators: [0],
        ),
      );
    }

    return barChartGroups;
  }
}
