import os

from flask import Flask

# Creating the application factory function
def create_app(test_config=None):
    # Create and configure the app

    # Creating the Flask instance
        # Name is the name of the current python module

        # Instance_relative_config=True tells the app that configuration files are relative
        # to the instance folder, located outside the flaskr package
    app = Flask(__name__, instance_relative_config=True)

    # Sets some default configuration
    app.config.from_mapping(
        SECRET_KEY='dev',
        DATABASE=os.path.join(app.instance_path, 'flaskr.sqlite'),
    )

    if test_config is None:
        # Load the instance config, if it exists, when not testing
        app.config.from_pyfile('config.py', silent=True)
    else:
        # Load the test config if passed in
        app.config.from_mapping(test_config)

    # Ensure the instance folder exists
    try:
        os.makedirs(app.instance_path)
    except OSError:
        pass

    # A simple page that says hello
    @app.route("/hello")
    def hello():
        return "Hello, World!"

    from . import db
    db.init_app(app)

    return app