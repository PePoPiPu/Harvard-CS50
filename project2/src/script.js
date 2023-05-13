import './styles.css'
import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'

// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

// Camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 10000)
camera.position.z = 5

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas })
renderer.setSize(window.innerWidth, window.innerHeight)
renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setClearColor(0x000000); // Set clear color to black
camera.aspect = window.innerWidth / window.innerHeight;
camera.updateProjectionMatrix();

// Controls
const controls = new OrbitControls(camera, renderer.domElement)

// Geometry
const galaxySize = 1000
const points = []

for (let i = 0; i < 10000; i++) {
  const angle = Math.random() * Math.PI * 2
  const distance = Math.random() * galaxySize
  const height = Math.random() * 2 - 1

  const x = Math.cos(angle) * distance
  const y = height * galaxySize
  const z = Math.sin(angle) * distance

  points.push(new THREE.Vector3(x, y, z))
}

const geometry = new THREE.BufferGeometry().setFromPoints(points)

// Colors
const colors = []
const color1 = new THREE.Color(0x8000ff) // Starting color
const color2 = new THREE.Color(0x00ff00) // Ending color

for (let i = 0; i < points.length; i++) {
  const t = i / points.length
  const color = new THREE.Color().lerpColors(color1, color2, t)
  colors.push(color.r, color.g, color.b)
}

geometry.setAttribute('color', new THREE.Float32BufferAttribute(colors, 3))

// Material
const vertexShader = `
  varying vec3 vColor;

  void main() {
    vColor = color;
    gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0);
  }
`

const fragmentShader = `
  varying vec3 vColor;

  void main() {
    gl_FragColor = vec4(vColor, 1.0);
  }
`

const material = new THREE.ShaderMaterial({
  vertexShader,
  fragmentShader,
  vertexColors: true,
})

// Mesh
const galaxy = new THREE.Points(geometry, material)
scene.add(galaxy)
galaxy.position.set(0, 0, 0);

// Animation loop
function animate() {
  requestAnimationFrame(animate)

  // Rotate the galaxy
  galaxy.rotation.y += 0.001

  // Render the scene
  renderer.render(scene, camera)
}

// Start the animation loop
animate()
