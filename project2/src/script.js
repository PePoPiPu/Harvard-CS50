import './styles.css';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';

// Canvas
const canvas = document.querySelector('canvas.webgl');

// Scene
const scene = new THREE.Scene();

// Camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 10000);
camera.position.z = 1500;

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(window.innerWidth, window.innerHeight);

// Controls
const controls = new OrbitControls(camera, renderer.domElement);

// Geometry
const galaxySize = 1000;
const points = [];

const numPoints = 10000;
const spiralTurns = 10;
const spiralHeight = 2;
const spiralRadius = 10;

for (let i = 0; i < numPoints; i++) {
  const t = i / numPoints;
  const angle = spiralTurns * 2 * Math.PI * t;
  const height = (t * 2 - 1) * spiralHeight;
  const radius = spiralRadius * t;

  const x = Math.cos(angle) * radius;
  const y = height * galaxySize;
  const z = Math.sin(angle) * radius;

  points.push(new THREE.Vector3(x, y, z));
}

const geometry = new THREE.BufferGeometry().setFromPoints(points);

// Colors
const colors = [];

const colorStart = new THREE.Color(0x8000ff); // Starting color
const colorEnd = new THREE.Color(0x00ff00); // Ending color

for (let i = 0; i < points.length; i++) {
  const t = i / points.length;
  const color = new THREE.Color().lerpColors(colorStart, colorEnd, t);
  colors.push(color.r, color.g, color.b);
}

geometry.setAttribute('color', new THREE.Float32BufferAttribute(colors, 3));

// Material
const material = new THREE.PointsMaterial({ vertexColors: true });

// Mesh
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