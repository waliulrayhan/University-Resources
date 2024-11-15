import tensorflow as tf
# Load your trained Keras model
model = tf.keras.models.load_model('model_trained.p')
# Convert the model to TensorFlow Lite format
converter = tf.lite.TFLiteConverter.from_keras_model(model)
tflite_model = converter.convert()
# Save the converted model to a file
with open('model.tflite', 'wb') as f:
    f.write(tflite_model)
