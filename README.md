
# Sentiment Analysis with Arduino Indicator

This project implements a Sentiment Analysis model using Python (Scikit-Learn) and integrates it with an Arduino-based LED indicator to visualize the sentiment of text in real-time.

## Project Structure

- `data/`: Contains training (`train.csv`) and testing (`test.csv`) datasets.
- `src/`: Python source code.
    - `model.py`: Script to preprocess data, train the model, and save artifacts.
    - `main.py`: CLI application for real-time sentiment prediction.
- `arduino/`: Arduino sketch (`led_controller.ino`) for the hardware indicator.
- `docs/`: Documentation and legacy files.

## Setup

1.  **Clone the repository**:
    ```bash
    git clone https://github.com/saksham7saxena/sentiment-analysis.git
    cd sentiment-analysis
    ```

2.  **Install Dependencies**:
    It is recommended to use a virtual environment.
    ```bash
    pip install -r requirements.txt
    ```

## Usage

### 1. Train the Model
Before running the application, you need to train the model on the dataset.
```bash
python src/model.py
```
This will generate `src/model.pkl` and `src/vectorizer.pkl`.

### 2. Run the Application
Start the Command Line Interface (CLI) to input text and see sentiment predictions.
```bash
python src/main.py
```
Type a sentence when prompted, and the script will output the predicted sentiment (Positive, Neutral, Negative).

## Arduino Integration

The `src/main.py` script is designed to communicate with an Arduino via Serial (USB).

**Hardware Setup**:
- Connect LEDs to digital pins (configure in `led_controller.ino`).
- Upload `arduino/led_controller.ino` to your Arduino board.

**Serial Communication**:
- **'1'**: Positive Sentiment (e.g., Green LED / Blink)
- **'0'**: Neutral Sentiment (e.g., Yellow LED / Steady)
- **'2'**: Negative Sentiment (e.g., Red LED / Off)

*Note: You may need to uncomment and configure the `serial` connection code in `src/main.py` with the correct COM port.*