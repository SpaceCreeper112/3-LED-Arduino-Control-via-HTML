from flask import Flask, render_template, request
import serial

arduino = serial.Serial('COM3', 115200)
app = Flask(__name__)

def activateLED(num: int):
    arduino.write(bytes([num]))

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/command', methods=["POST"])
def coms():
    raw = request.get_data()
    ledNo = int(raw.decode())
    activateLED(ledNo)
    return "ok"

if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=False)