# Pocket Galaxy
#### Video Demo: https://youtu.be/jOvUn5R2_RQ
#### Description: Three.js App that creates a customizable galaxy

## 1. Introduction: What is Pocket Galaxy?
### Pocket Galaxy is an app implemented in JavaScript using the Three.js JavaScript library. It consits of a 3D rendered galaxy that can be customized in the 4 following ways:
1. You can change the size of the galaxy.
2. You can set the number of arms you want your spiral galaxy to have.
3. You can change the base color of the galaxy.
4. You can customize the color of the center of your galaxy.

### 1.1 App characteristics:
### This pocket galaxy has a set of characteristics that have been implemented either through JavaScript, GSAP, CSSRulePlugin, gui.dat or through the use of Three.js postprocessing features. This characteristics are:
1. An animated introductory view of the app using a combination of JavaScript, GSAP and CSSRulePlugin.
2. An animated transition from the introductory view to the close-up view of the galaxy has been implemented with a combination of JavaScript, GSAP and Three.js camera coordinates.
3. A bloom effect implemented with postprocessing features from Three.js
4. A simple interactive GUI implemented with gui.dat.
5. Full galaxy customization through the use of several functions implemented with JavaScript.
### How these characteristic where implemented and their functionality and code will be explained further down this document.

## 2. Project's file structure:
```
├── project
│   ├── bundler
│   │   ├── webpack.common.js
│   │   ├── webpack.dev.js
│   │   ├── webpack.prod.js
│   ├── node_modules
│   │   ├── contains all the modules
│   ├── src
│   │   ├── index.html
│   │   ├── script.js
│   │   ├── styles.css
│   ├── static
│   │   ├── star.png
│   ├── package-lock.json
│   ├── package.json
│   ├── README.md
```
### The most important files we're going to see in this project are:
1. The src folder containing our main code including the script, the stylesheet and the html file.
2. The static folder containing a 10px by 10px png file for our custom star texture.
### I believe this file structure is organized and simple to understand.

## 3. Project's implementation:
### 3.1 The basic setting:
Let's start by explaining how the project started. I wanted to have a customizable galaxy (a 3 object) in a region of space. For that, I had to first create a canvas for everything to render on:

```
    <canvas class="webgl"></canvas>
```
I used the following CSS settings for the html document and its body:
```
*
{
    margin: 0;
    padding: 0;
}

html,
body {
  margin: 0;
  padding: 0;
  overflow: hidden;
  height: 100vh;
  font-family: 'Inter', sans-serif;
  color: white;
}
```

And the following settings for the canvas so it could be properly positioned:
```
.webgl {
  display: block;
  position: fixed;
  top: 0;
  left: 0;
  outline: none;
}
```

Good! Now I had something to render on so I started with my main script.js file, starting with the imports:
```
import './styles.css';
import * as THREE from 'three';
```
I imported the styles sheet and the complete Three.js library. Afterwards, I started by selecting my canvas, declaring the scene and setting my main camera