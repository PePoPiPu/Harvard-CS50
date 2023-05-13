import './styles.css';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';

// Canvas
const canvas = document.querySelector('canvas.webgl');

// Scene
const scene = new THREE.Scene();

// Camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 10000);
camera.position.z = 30;

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(window.innerWidth, window.innerHeight);

// Controls
const controls = new OrbitControls(camera, renderer.domElement);

// Galaxy Parameters
const galaxySize = 10; // Controls the size of the galaxy
const armCount = 4; // Number of arms in the galaxy
const starCount = 10000; // Total number of stars in the galaxy
const armRotationSpeed = 0.005; // Controls the rotation speed of the arms

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
  const armRotation = armAngle + (i % (starCount / armCount)) * armRotationSpeed;

  const angle = armRotation;
  const radius = Math.sqrt(Math.random()) * galaxySize;
  const height = Math.random() * 0.2;

  const x = Math.cos(angle) * radius;
  const y = height * galaxySize;
  const z = Math.sin(angle) * radius;

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

  // Rotate the arms
  galaxy.rotation.y += armRotationSpeed;

  // Render the scene
  renderer.render(scene, camera);
}

// Start the animation loop
animate();

