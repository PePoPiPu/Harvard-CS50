import './styles.css';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';

// Canvas
const canvas = document.querySelector('canvas.webgl');

// Scene
const scene = new THREE.Scene();

// Camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.set(0, 10, 30);

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(window.innerWidth, window.innerHeight);

// Controls
const controls = new OrbitControls(camera, renderer.domElement);

// Galaxy Parameters
const armCount = 4; // Number of arms in the galaxy
const starCount = 10000; // Total number of stars in the galaxy
const armLength = 20; // Length of each arm
const armSpread = 10; // Spread of the arms

// Material
const material = new THREE.PointsMaterial({
  size: 0.05, // Size of each star
  vertexColors: true, // Enable vertex colors
});

// Geometry
const geometry = new THREE.BufferGeometry();
const positions = new Float32Array(starCount * 3);
const colors = new Float32Array(starCount * 3);

// Generate the stars
for (let i = 0; i < starCount; i++) {
  const armIndex = Math.floor(i / (starCount / armCount));
  const armAngle = (armIndex / armCount) * Math.PI * 2;

  const angle = armAngle + Math.random() * Math.PI / 4 - Math.PI / 8; // Randomize the angle within a small range
  const radius = Math.random() * armLength;
  const height = Math.random() * 0.1;

  const x = Math.cos(angle) * (armSpread + radius);
  const y = height * armSpread;
  const z = Math.sin(angle) * (armSpread + radius);

  const color = new THREE.Color().setHSL(angle / (Math.PI * 2), 1, 0.5); // Color based on angle

  positions[i * 3] = x;
  positions[i * 3 + 1] = y;
  positions[i * 3 + 2] = z;

  colors[i * 3] = color.r;
  colors[i * 3 + 1] = color.g;
  colors[i * 3 + 2] = color.b;
}

geometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));
geometry.setAttribute('color', new THREE.BufferAttribute(colors, 3));

// Points
const galaxy = new THREE.Points(geometry, material);
scene.add(galaxy);

// Animation loop
function animate() {
  requestAnimationFrame(animate);

  // Rotate the galaxy
  galaxy.rotation.y += 0.001;

  // Render the scene
  renderer.render(scene, camera);
}

// Start the animation loop
animate();