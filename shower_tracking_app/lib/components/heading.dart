import 'package:flutter/material.dart';

class Heading extends StatelessWidget {
  Heading(this.title);

  final String title;

  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(left: 20, top: 20, bottom: 10  ),
      child: Text(
        title,
        style: const TextStyle(
          fontSize: 40,
          fontWeight: FontWeight.bold,
          color: Colors.white,
        ),
      ),
    );
  }
}
