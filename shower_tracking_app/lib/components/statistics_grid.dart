import 'package:flutter/material.dart';
import 'package:shower_tracking_app/components/custom_card.dart';

class StatisticsGrid extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    var padding = EdgeInsets.zero;

    return AspectRatio(
      aspectRatio: 3,
      child: Expanded(
        child: Row(
          children: [
            _card(padding, "AVG. Water", "36L"),
            _card(padding, "Total Water", "252L"),
            _card(padding, "Total Energy", "26MJ"),
          ],
        ),
      ),
    );
  }

  Expanded _card(EdgeInsets padding, String title, String value) {
    return Expanded(
      child: CustomCard(
        child: SizedBox(
          height: double.infinity,
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Text(
                title,
                style: const TextStyle(
                  fontSize: 15,
                  color: Colors.white,
                ),
              ),
              SizedBox(height: 10),
              Text(
                value,
                style: const TextStyle(
                  fontSize: 33,
                  color: Colors.white,
                ),
              ),
            ],
          ),
        ),
        padding: padding,
      ),
    );
  }
}
