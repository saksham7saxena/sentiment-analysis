
import sys
import pickle
import time
from model import predict_sentiment, preprocess

# Helper to load model/vectorizer
def load_artifacts():
    try:
        with open('src/model.pkl', 'rb') as f:
            model = pickle.load(f)
        with open('src/vectorizer.pkl', 'rb') as f:
            vectorizer = pickle.load(f)
        return model, vectorizer
    except FileNotFoundError:
        print("Model or vectorizer not found. Please run 'python src/model.py' to train the model first.")
        sys.exit(1)

def map_sentiment_to_arduino(sentiment):
    """
    Maps sentiment string to Arduino command.
    Positive -> '2' (Party/Blink)
    Neutral -> '1' (On)
    Negative -> '0' (Off)
    (Adjusted mapping to match common logic, original code had 0, 1, 2 but didn't specify meaning clearly in .ino)
    Re-checking .ino logic:
    '0' -> LED HIGH (On)
    '1' -> LED Blinks (Party)
    '2' -> LED LOW (Off)
    
    So:
    Negative -> '2' (Off)
    Neutral -> '0' (On)
    Positive -> '1' (Party)
    """
    if sentiment == 'positive':
        return '1'
    elif sentiment == 'neutral':
        return '0'
    elif sentiment == 'negative':
        return '2'
    return '0'

def main():
    print("Loading Sentiment Analysis Model...")
    model, vectorizer = load_artifacts()
    
    print("Sentiment Analysis CLI")
    print("Type a sentence to analyze its sentiment (or 'quit' to exit).")
    
    # Optional: Setup Serial Connection
    # import serial
    # ser = serial.Serial('COM3', 9600) # Update COM port as needed
    
    while True:
        user_input = input("\nEnter text: ")
        if user_input.lower() == 'quit':
            break
            
        prediction = predict_sentiment([user_input], model, vectorizer)
        sentiment = prediction[0]
        
        print(f"Predicted Sentiment: {sentiment}")
        
        arduino_cmd = map_sentiment_to_arduino(sentiment)
        print(f"Arduino Command: {arduino_cmd}")
        
        # if ser:
        #     ser.write(arduino_cmd.encode())

if __name__ == "__main__":
    main()
